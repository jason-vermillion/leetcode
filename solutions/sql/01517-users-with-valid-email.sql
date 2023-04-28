# https://leetcode.com/problems/find-users-with-valid-e-mails/description/
# 1517. Find Users With Valid E-Mails
select user_id, name, mail
from Users
where REGEXP_LIKE(mail, '^[A-Za-z][A-Za-z0-9-_.]*@leetcode\\.com$');