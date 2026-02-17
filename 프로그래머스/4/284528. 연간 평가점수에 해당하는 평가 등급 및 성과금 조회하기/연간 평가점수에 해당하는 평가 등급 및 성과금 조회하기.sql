WITH AVERAGE_SCORE AS (
    SELECT EMP_NO, AVG(SCORE) AS AVERAGE
    
    FROM HR_GRADE
    
    GROUP BY EMP_NO
)

SELECT 
    E.EMP_NO, 
    E.EMP_NAME, 
    (
        CASE
            WHEN A.AVERAGE >= 96 THEN 'S'
            WHEN A.AVERAGE >= 90 AND A.AVERAGE < 96 THEN 'A'
            WHEN A.AVERAGE >= 80 AND A.AVERAGE < 90 THEN 'B'
            WHEN A.AVERAGE < 80 THEN 'C'        
        END
    ) AS GRADE,
    (
        CASE
            WHEN A.AVERAGE >= 96 THEN E.SAL * 0.2
            WHEN A.AVERAGE >= 90 THEN E.SAL * 0.15
            WHEN A.AVERAGE >= 80 THEN E.SAL * 0.1
            ELSE 0
        END
    ) AS BONUS
    
FROM HR_EMPLOYEES E

JOIN AVERAGE_SCORE A ON E.EMP_NO = A.EMP_NO

ORDER BY E.EMP_NO ASC;