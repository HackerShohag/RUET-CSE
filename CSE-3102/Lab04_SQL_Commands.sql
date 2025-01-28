-- # Level 1
-- Query 1.1: Display the name, IMDb rating and genre of all the movies with an IMDB rating greater than or equal to 8.0.
SELECT
    Movie_Name,
    Genre
FROM
    Movie
WHERE
    IMDB_Rating >= 8.0;

-- Query 1.2: Find how many movies are there in each genre with an IMDB rating greater than or equal to 8.0.
SELECT
    Genre,
    COUNT(Movie_Name)
FROM
    Movie
WHERE
    IMDB_Rating >= 8.0
GROUP BY
    Genre;

-- Query 1.3: Find the name and the average IMDb rating of those genres whose average IMDb rating is greater than or equal to 8.0.
SELECT
    Genre,
    AVG(IMDB_Rating)
FROM
    Movie
GROUP BY
    Genre
HAVING
    AVG(IMDB_Rating) >= 8.0;

-- Query 1.4: Find the name, number of films and number of awards of the director who directed the most number of movies.
SELECT
    Director_Name,
    MAX(No_Of_Films) AS No_Of_Films,
    No_Of_Awards
FROM
    Director;

-- Query 1.5: Find the name, current age, number of films and number of awards of the youngest actor.
SELECT
    Actor_Name,
    (YEAR(NOW()) - Birth_Year) AS AGE,
    No_Of_Films,
    No_Of_Awards
FROM
    Actor
WHERE
    Birth_Year =(
    SELECT
        MAX(Birth_Year)
    FROM
        Actor
);

-- # Level 2
-- Query 2.1: Find the name, number of films as a director, number of films as an actor, number of awards as a director and number of awards as an actor of all the directors. (If a director never acted in any film then number of films and number of awards as an actor will be null)
SELECT
    Director.Director_Name,
    Director.No_Of_Films AS FilmsAsDirector,
    Director.No_Of_Awards AS AwardsAsDirector,
    Actor.No_Of_Films AS FilmsAsActor,
    Actor.No_Of_Awards AS AwardsAsActor
FROM
    Director
LEFT JOIN Actor ON Director.Person_ID = Actor.Person_ID;

-- Query 2.2: Find the name, number of films as a director, number of films as an actor, number of awards as a director and number of awards as an actor of all the actors and directors.
SELECT
    Actor.Actor_Name,
    Director.No_Of_Films AS FilmsAsDirector,
    Actor.No_Of_Films AS FilmsAsActor,
    Director.No_Of_Awards AS AwardsAsDirector,
    Actor.No_Of_Awards AS AwardsAsActor
FROM
    Actor
    LEFT OUTER JOIN Director ON Director.Person_ID = Actor.Person_ID;

-- Query 2.3: Find the name, number of films and number of awards of those actors who never directed any film.
SELECT
    Actor_Name AS NAME,
    No_Of_Films,
    No_Of_Awards
FROM
    Actor
WHERE
    Person_ID NOT IN(
SELECT
    Person_ID
FROM
    Director
);

-- Query 2.4: Find the name, IMDb rating and genre of those movies whose IMDb Rating is above average.
SELECT
    Movie_Name,
    IMDB_Rating,
    Genre
FROM
    Movie
WHERE
    IMDB_Rating > (
    SELECT
        AVG(IMDB_Rating)
    FROM
        Movie
);

-- Query 2.5: Among the average IMDb ratings of all the movie genres, find the highest average IMDb rating.
SELECT
    AVG(IMDB_Rating) AS AVG_Rating
FROM
    Movie
GROUP BY
    Genre
ORDER BY
    AVG_Rating
DESC
LIMIT 1;
