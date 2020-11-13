from typing import Tuple

from elasticsearch import Elasticsearch
from elasticsearch.client import IndicesClient

from pyquery import PyQuery as pq

import tarfile
import os

def load_data(es: Elasticsearch) -> None:
    """
    This function loads data from the tarball "wiki-small.tar.gz" 
    to the Elasticsearch cluster

    Parameters
    ----------
    es : Elasticsearch
        The Elasticsearch client
    
    Returns
    -------
    None
    """

    tar = tarfile.open("wiki-small.tar.gz", "r:gz")
    tar.extractall()
    
    for root, dirs, files in os.walk(os.path.dirname(os.path.realpath(__file__))):
        for filename in files:
            if filename.endswith(".html"):
                filepath = os.path.join (root, filename)
                f = open(filepath, "r")
                contents = f.read()
                
                index_body = {
                    "title" : parse_html(contents)[0],
                    "body" : parse_html(contents)[1],
                }

                es.index(index = "wikipedia", doc_type = "_doc", body = index_body)
    tar.close()
    

def parse_html(html: str) -> Tuple[str, str]:
    """
    This function parses the html, strips the tags an return
    the title and the body of the html file.

    Parameters
    ----------
    html : str
        The HTML text

    Returns
    -------
    Tuple[str, str]
        A tuple of (title, body)
        """

    file = pq(html)
    title = file("title").text()
    body = file("body").text()

    return title, body;



def create_wikipedia_index(ic: IndicesClient) -> None:
    """
    Add an index to Elasticsearch called 'wikipedia'

    Parameters
    ----------
    ic : IndicesClient
        The client to control Elasticsearch index settings

    Returns
    -------
    None
    """
    
    index_body = {
    	"settings": {
    		"analysis": {
                "filter": {
                        "my_stops": {
                            "type": "stop",
                            "stopwords_path": "stopwords.txt"
                        }           
                 },
   				 "analyzer": {
    				"my_analyzer": {
    					"type": "custom", 
    					"tokenizer": "standard",
    					"filter": [
                            "my_stops",
                            "lowercase"
                            
                        ]
                    }

                }
    		}
    	}
    }

    res = ic.create (index = "wikipedia", body = index_body)
