-- 코드를 입력하세요
WITH NAME_TABLE AS 
    (
        SELECT NAME 
        
        FROM ANIMAL_INS
        
        WHERE NAME IS NOT NULL
        
        GROUP BY NAME
        
    )
    
SELECT COUNT(*) AS 'COUNT'

FROM NAME_TABLE;