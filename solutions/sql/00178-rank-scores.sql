## https://leetcode.com/problems/rank-scores/
## mysql 178. Rank Scores
SELECT
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) "rank"
FROM Scores;