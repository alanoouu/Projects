import pymssql
conn = pymssql.connect(host='cypress.csil.sfu.ca',
                       user='s_alano', password='4Mqg43YmfdQAE3J6',
                       database='alano354')

mycursor = conn.cursor()

add_record_isrc = raw_input('Please enter a isrc: ')
if not (0 <= len(add_record_isrc) <=  14):
    while True:
        print 'ISRC cannot be less than 1 character or greater than 14 characters'
        add_record_isrc = raw_input('Please re-enter a isrc: ')
        if (0 <= len(add_record_isrc) <=  14):
            break

add_record_title = raw_input('Please enter a title: ')
if not (0 <= len(add_record_title) <=  20):
    while True:
        print 'Title cannot be less than 1 character or greater than 20 characters'
        add_record_title = raw_input('Please re-enter a title: ')
        if (0 <= len(add_record_title) <=  20):
            break

add_record_year = raw_input('Please enter a year: ')
while True:
    try:
        test_convert = int(add_record_year)
        break;
    except ValueError:
        print 'Please enter an integer'
        add_record_year = raw_input('Please re-enter a year: ')
   
add_record_artistname = raw_input('Please enter a artist name: ')
if not (0 <= len(add_record_artistname) <=  20):
    while True:
        print 'Artist name cannot be less than 1 character or greater than 20 characters'
        add_record_artistname = raw_input('Please re-enter a artist name: ')
        if (0 <= len(add_record_artistname) <=  20):
            break

mycursor.execute(
    "INSERT INTO Song (isrc, title, year, artistname) VALUES (%s, %s, %d, %s)" , (add_record_isrc, add_record_title, int(add_record_year), add_record_artistname))

print 'Song record successfully entered'

conn.commit()
mycursor.close()

print"\n Song isrcs and titles by the artist just added"
mycursor = conn.cursor()

mycursor.execute('SELECT isrc, title FROM Song WHERE isrc=%s', add_record_isrc)
row = mycursor.fetchone()
print "isrc: %s, title: %s" %(row[0], row [1])

mycursor.close()

