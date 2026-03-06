SELECT DISTINCT
    U.USER_ID,
    U.NICKNAME,
    CONCAT_WS(
        ' ',
        U.CITY,
        U.STREET_ADDRESS1,
        U.STREET_ADDRESS2
    ) AS 전체주소,
    CONCAT_WS(
        '-',
        SUBSTR(U.TLNO, 1, 3),
        SUBSTR(U.TLNO, 4, 4),
        SUBSTR(U.TLNO, 8, 4)
    ) AS 전화번호
FROM
    USED_GOODS_USER U
JOIN 
    USED_GOODS_BOARD B
    ON U.USER_ID = B.WRITER_ID
GROUP BY 
    USER_ID
HAVING
    COUNT(USER_ID) >= 3
ORDER BY 
    U.USER_ID DESC;
    