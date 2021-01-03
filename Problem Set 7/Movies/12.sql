SELECT title FROM movies
WHERE id IN (SELECT movie_id FROM stars
JOIN people 
ON stars.person_id = people.id
WHERE name = "Johnny Depp" 
and movie_id IN (SELECT movie_id from stars 
JOIN people
ON stars.person_id = people.id
WHERE name = "Helena Bonham Carter"))