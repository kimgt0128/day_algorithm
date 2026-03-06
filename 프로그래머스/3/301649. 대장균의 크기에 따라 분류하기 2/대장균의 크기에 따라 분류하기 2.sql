WITH TARGET AS (
    SELECT 
        *,
        NTILE(4) OVER(ORDER BY SIZE_OF_COLONY DESC) AS CLASS
    FROM
        ECOLI_DATA
)

SELECT
    ID,
    (
        CASE
            WHEN CLASS = 1 THEN 'CRITICAL'
            WHEN CLASS = 2 THEN 'HIGH'
            WHEN CLASS = 3 THEN 'MEDIUM'
            WHEN CLASS = 4 THEN 'LOW'
        END
    ) AS COLONY_NAME
    
FROM TARGET

ORDER BY ID ASC;
    