-- # Level 1
-- Query 1.1: Display the name and IMBb rating of all the movies according to their IMDB rating (in descending order); if multiple movies have the same IMDB rating then rearrange those movies alphabetically according to their names.
SELECT
    Movie_Name,
    IMDB_Rating
from
    Movie
ORDER BY
    IMDB_Rating DESC,
    Movie_Name DESC;

-- Query 1.2: Find the total number of movies in the database.
SELECT
    COUNT(Movie_ID)
from
    Movie;

-- Query 1.3: Find how many movie-genres are there in the database.
SELECT
    COUNT(DISTINCT Genre)
FROM
    Movie;

-- Query 1.4: Find the average IMDB rating of the movies of the drama genre.
SELECT
    AVG(IMDB_Rating)
FROM
    Movie
WHERE
    Genre = 'Drama';

-- Query 1.5: Find the total number of movies in each genre.
SELECT
    COUNT(Movie_ID),
    Genre
FROM
    Movie
GROUP BY
    Genre;

-- # Level 2
-- Query 2.1: Find the number of movies directed by a director on average.
SELECT
    AVG(No_Of_Films)
FROM
    Director;

-- Query 2.2: Find the name, genre, IMDb rating and the name of the director of all the movies directed by Satyajit Ray, Zahir Raihan, Rituparno Ghosh and Kaushik Ganguly.
SELECT
    Movie_Name,
    Genre,
    IMDB_Rating,
    Director.Director_Name
from
    Movie
    JOIN Director ON Director.Person_ID = Movie.Director_ID
WHERE
    Director.Director_Name IN (
        'Satyajit Ray',
        'Zahir Raihan',
        'Rituparno Ghosh',
        'Kaushik Ganguly'
    );

-- Query 2.3: Find the name and current age of all the directors and actors.
SELECT
    Director_Name As Name,
    YEAR (NOW ()) - Birth_Year AS Age
from
    Director
UNION
SELECT
    Actor_Name as Name,
    YEAR (NOW ()) - Birth_Year AS Age
from
    Actor;

-- Query 2.4: Find the name, current age, number of films as an actor and number of films as a director of those actors who directed at least one film.
SELECT
    Actor_Name As Name,
    YEAR (NOW ()) - Actor.Birth_Year AS Age,
    Actor.No_Of_Films as AsActor,
    Director.No_Of_Films as AsDirector
from
    Actor
    JOIN Director ON Actor.Person_ID = Director.Person_ID;

-- Query 2.5: Consider that there is no No_of_Films attribute in the Director relation. Now find the name of all the directors and number of movies directed by each director.
SELECT
    Director_Name As Name,
    COUNT(Movie.Movie_ID) as Movies
from
    Director
    JOIN Movie ON Movie.Director_ID = Director.Person_ID
GROUP BY
    Director.Director_Name;