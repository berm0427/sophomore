
SELECT * FROM Movie
WHERE year = 1990 AND studioName = 'Disney';

--

SELECT DISTINCT MovieExec.name
FROM Movie
JOIN MovieExec ON Movie.producerC = MovieExec.cert
WHERE Movie.year = 1990 AND Movie.studioName = 'Disney'
ORDER BY MovieExec.name ASC;

--

SELECT Movie.title AS ShortestMovie, MovieStar.name AS LeadActor, Movie.studioName AS Studio
FROM Movie
JOIN StarsIn ON Movie.title = StarsIn.movieTitle AND Movie.year = StarsIn.movieYear
JOIN MovieStar ON StarsIn.starName = MovieStar.name
WHERE Movie.length IS NOT NULL
ORDER BY Movie.year DESC, Movie.length ASC
LIMIT 1;

--

SELECT title, length
FROM Movie
WHERE year between 1990 and 1999 AND studioName = 'Disney';

--

SELECT title
FROM Movie
WHERE year > 1970 AND inColor = 0;

--

SELECT title
FROM Movie
WHERE (studioName = 'MGM' AND year > 1970) OR (studioName = 'MGM' AND length < 90);

--

SELECT M.title, COUNT(S.starName) AS maleActorsCount
FROM Movie M
INNER JOIN StarsIn S ON M.title = S.movieTitle AND M.year = S.movieYear
WHERE S.starName IN 
(
    SELECT starName
    FROM MovieStar
    WHERE gender = 'M'
)
GROUP BY M.title;

--

