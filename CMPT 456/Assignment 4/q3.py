"""
Q1: Create index and load data
Please fill in the missing content in each function.
"""

import assignment4 as a4
from elasticsearch import Elasticsearch
from elasticsearch.client import IndicesClient


def main():
    """
    The main function, do not change any code here
    """

    es = Elasticsearch()
    ic = IndicesClient(es)
    a4.create_wikipedia_index(ic)
    a4.load_data(es)

    print("The top ranked title:", search_and_rank(es))
    add_synonyms_to_index(ic)
    print("The top ranked title:", search_and_rank(es))
    print(how_does_rank_work())


def search_and_rank(es: Elasticsearch) -> str:
    """
    Based on the search in Q2, rank the documents by the terms "BC", "WA" and "AB"
    in the document body.
    Return the **title** of the top result.

    Parameters
    ----------
    es : Elasticsearch
        The Elasticsearch client
    
    Returns
    -------
    str
        The title of the top ranked document
    """

    res = es.search (index = 'wikipedia', body = {
        'query':{
             'bool':{
                 'must':{
                     'bool':{
                         'should':[
                             {'match': {'body':'lake'}},
                             {'match': {'body':'tour'}}
                         ]
                     }
                 },
                 'must_not':{
                     'match_phrase':{
                         'body':'Please improve this article if you can.'
                      }
                  },
                 "should": [
                    
                    {'match': {
                        'body': {
                            "analyzer" : "my_analyzer",
                            'query': 'BC',
                            'boost': 2
                            }
                        }
                    }, 
                    {'match': {
                        'body': {
                            "analyzer" : "my_analyzer",
                            'query': 'AB',
                            'boost': 1
                            }
                        }
                    },
                    {'match': {
                        'body': {
                            "analyzer" : "my_analyzer",
                            'query': 'WA',
                            'boost': 1
                            }
                        }
                    }
                ]
            }
        },
        'size' : 1  
    })
    
    for doc in res['hits']['hits']:
        top_doc_title = doc['_source']['title']

    return (top_doc_title)


def add_synonyms_to_index(ic: IndicesClient) -> None:
    """
    Modify the index setting, add synonym mappings for "BC" => "British Columbia",
    "WA" => "Washington" and "AB" => "Alberta"

    Parameters
    ----------
    ic : IndicesClient
        The client for control index settings in Elasticsearch
    
    Returns
    -------
    None
    """

    ic.delete (index = "wikipedia")

    index_body = {
         "settings": {
            "analysis": {
                 "analyzer": {
                    "my_analyzer": {
                        "type": "custom", 
                        "tokenizer": "standard",
                        "filter": [
                            "my_synonyms",
                            "lowercase", 
                            "my_stops"
                                                       
                        ]
                    }
                },
                "filter": {
                        "my_stops": {
                            "type": "stop",
                            "stopwords_path": "stopwords.txt"
                        }, 
                        "my_synonyms": {
                            "type":"synonym",
                            "synonyms": [
                                "BC => British Columbia",
                                "AB => Alberta",
                                "WA => Washington"
                            ]
                        }          
                 }
            }
            },
            "mappings": {
                        "properties": {
                            "body": {
                                "type": "text",
                                "analyzer": "my_analyzer"
                        }
                }
            }
        }
     

    ic.create (index = "wikipedia", body = index_body)

    es = Elasticsearch()
    a4.load_data(es)


def how_does_rank_work() -> str:
    """
    Please write the answer of the question:
    'how does rank work?' here, returning it as a str.

    Returns
    -------
    str, the answer
    """
    ans = ('\n    Now, how does Q3.1 and Q3.2 change the order of the returned documents. Before running add_synonyms_to_index (function implemented in Q3.1), when search_and_rank (function implemented in Q3.2) is run, in addition to the query requirements set out in Q2.2, it will search through the documents and match and score all the documents that contain the characters “BC”, “AB”, and “WA”, with documents containing “BC” given the highest score and therefore ranked the highest, and documents containing “AB” and “WA” given a higher, but a not as high as “BC” score, therefore ranked higher than other documents, but not as high as documents containing “BC”. Notice that it is the characters “BC”, “AB”, and “WA” that are matched, and not the words “British Columbia”, “Alberta”, and “Washington” because that is precisely what we told search_and_rank to do. We told search_and_rank that whenever it sees “BC”, “AB”, and “WA”, Elasticsearch should adjust the scores of the corresponding documents accordingly. In other words, search_and_rank not only finds the matching documents, but also ranks them so that documents containing “BC” will be ranked on top, and documents containing “AB” and documents containing “WA” ranked above other documents.'
            '\n\n    But that is not what we want, what we want are documents that contain the terms “British Columbia”, “Alberta”, and “Washington”. A fix to this is by running the add_synonyms_to_index function created in Q3.1. So, by running add_synonyms_to_index, we add the synonym filter into the “wikipedia” index, and this basically tells Elasticsearch that “BC” is an abbreviated version of “British Columbia”, “AB” is “Alberta”, and “WA” is “Washington”. Now that Elasticsearch knows the abbreviations, when search_and_rank is run again, only the terms “British Columbia”, “Alberta”, and “Washington” are matched and not the characters “BC”, “AB”, and “WA” because search_and_rank now knows to treat “BC” as “British Columbia”, “AB” as “Alberta”, and “WA” as “Washington”, resulting in the changed order of the returned documents.'
            '\n\n    The details on the implementation of the functions in Q3.1 and Q3.2 are as follows:'
            '\n\n    In Q3.1, we “set the stage” and do some preparation for the search_and_rank function completed in Q3.2. Before completing Q3.1, as mentioned in the question description, Elasticsearch does not know what “BC”, “AB”, “WA” stand for; in other words, when Elasticsearch searches through the documents, it would for example, not know that “BC” is an abbreviation for “British Columbia”. This issue is what we try to solve in Q3.1. In Q3.1, I deleted the existing “wikipedia” index, created a new “wikipedia" index with the addition of a synonym token filter and a mapping to tell Elasticsearch to use the analyzer created, which contains the synonym filter, on the body portion of the document, and finally reloaded all the data. The main difference here is the addition of the synonym filter; I implemented the synonym filter in a way that tells Elasticsearch that “BC” is an abbreviated version of “British Columbia”, “AB” is “Alberta”, and “WA” is “Washington”.'
            '\n\n    Onto the search_and_rank function in Q3.2. As described in the question description, we want documents containing “BC” to be ranked on top, and documents containing “AB” and documents containing “WA” above other documents. To do this, I modified the search_without_improvement function by adding an additional “should” clause and three “match” clauses, each corresponding to one of “BC”, “AB”, and “WA”. In addition, in each of these “match” clauses, I assigned a “boost” score of 2, 1, 1 to the abbreviations “BC”, “AB”, and “WA” respectively. What the “boost” score does is to tell Elasticsearch that whenever it passes by one of the three abbreviations, it should give that particular document a higher score because it contains a relevant query.')

    return (ans)

if __name__ == "__main__":
    main()
