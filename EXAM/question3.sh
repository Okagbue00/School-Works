#!/bin/bash

#it contains my seven genre directories that are special
SPECIAL='hip-hop metal pop punk rap rock indie'

#it changes my working directory to music and terminates with a zero exit status
cd music || exit 1

#it list all my directories
ls -N
#writes its argument to standard output and then prints the string
#display on the console name of all the genre in the dir
echo '---------------------------------------------'
#prints on a newline character the genre
echo -n 'Select a genre from the above: '
#reads the genre

read GENRE

#it returns the genre executed
GENRE=${GENRE,,}
#prints the string
echo '---------------------------------------------'

#set my gen_subgenre to be empty
HAS_SUBGENRE=0

#iterates my loop to get the special genre
for S in $SPECIAL
do
  #checks if my S is a genre
    if [ $S == $GENRE ]
    then
      #and then assigns the has_genre to be 1
        HAS_SUBGENRE=1
        #breaks out of the loop

        break
    #makes decision and execute statement conditionally
    fi
done

#checks if the sub genre is equal to 1
#if the user enters one of the seven genre
if [ $HAS_SUBGENRE == 1 ]
then
  # it then displays the name of the genre of the file in a alphabetical order.
    ls -N -d $GENRE $GENRE/*$GENRE* | xargs -n 1 basename
    echo '---------------------------------------------'
    #prints the string in a new line
    echo -n 'Select a sub-genre from the above: '
    #then reads the subgenre
    read SUBGENRE
    SUBGENRE=${SUBGENRE,,}
    echo '---------------------------------------------'

 #checks if the subgenre and genre are equal
    if [ $SUBGENRE == $GENRE ]
    then
        HAS_SUBGENRE=0
    #makes decision and execute statement conditionally
    fi
fi

if [ $HAS_SUBGENRE == 1 ]
then
  #if the full genre is the genre and sub genre should be written in text file
  #makes the file to be written in txt
    FULL_GENRE=$GENRE/$SUBGENRE
    OUTPUT="../${SUBGENRE}_artists.txt"
    #or else the genre should just be written in text file
else
    FULL_GENRE=$GENRE
    OUTPUT="../${GENRE}_artists.txt"
# it makes decision and execute statement conditionally
fi


# arranges the file in the directory in an alphabetical order
# reads streams of data from standard input
ls $FULL_GENRE | xargs -n 1 basename > $OUTPUT

COUNT=0
#iterates to check if the artist is found in the file
for ARTIST in $(cat $OUTPUT)
do
  #it then overwrites it
    COUNT=$((COUNT+1))
#done accomplished
done
#it displays a message showing how many artists were found
echo "The total number of artists in the genre $FULL_GENRE were: $COUNT"


