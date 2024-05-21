-- # Level 1

-- Query 1.1: Find the name, genre, and IMDB rating of all the movies.
SELECT Movie_Name, Genre, IMDB_Rating from Movie;

-- Query 1.2: Display all the distinct movie-genres.
SELECT DISTINCT Genre from Movie;

-- Query 1.3: Find the name and current age of all the actors.
SELECT Actor_Name, (YEAR(NOW()) - Birth_Year) as AGE from Actor;

-- Query 1.4: Find all the movies of the thriller genre with an IMDB rating greater than or equal to 8.0.
SELECT * from Movie WHERE Genre = 'Thriller' and IMDB_Rating >= 8.0;

-- Query 1.5: Find the name, release year, IMDB rating, and the name of the director of all the movies.
SELECT Movie_Name, Year as RELEASE_YEAR, IMDB_Rating, Director.Director_Name from Movie
INNER JOIN Director ON Movie.Director_ID = Director.Person_ID;



-- # Level 2

-- Query 1.6: Find the name and number of awards of those directors whose name starts with a ‘S’ or a ‘A’.
SELECT Director_Name, No_Of_Awards from Director
WHERE Director_Name LIKE 'S%' OR Director_Name LIKE 'A%';

-- Query 1.7: Find the name and birth year of those directors whose name contains an ‘a’ as its 2nd last character.
SELECT Director_Name, Birth_Year from Director
WHERE Director_Name LIKE '%A_';

-- Query 1.8: Find the name, release year, and genre of all the movies which contain the word ‘Byomkesh’ anywhere in their name.
SELECT Movie_Name, Year, Genre from Movie
WHERE Movie_Name LIKE '%Byomkesh%';

-- Query 1.9: Find the name and IMDB rating of all the movies whose name consists of only 2 characters.
SELECT Movie_Name, IMDB_Rating from Movie
WHERE Movie_Name LIKE '__' ;
SELECT Movie_Name, IMDB_Rating from Movie
WHERE LENGTH(Movie_Name) = 2;

-- Query 1.10: Find the name and genre of all the movies whose name consists of at least 3 characters.
SELECT Movie_Name, Genre from Movie
WHERE LENGTH(Movie_Name) > 2;

-- Query 1.Last: Find the name and IMDB rating of all the movies which contain at most 9 characters in their name.
SELECT Movie_Name, IMDB_Rating from Movie
WHERE LENGTH(Movie_Name) < 10;
SELECT Movie_Name, IMDB_Rating from Movie
WHERE Movie_Name NOT LIKE '__________%';
