set YYYYmmdd=%date:~0,4%%date:~5,2%%date:~8,2%
set hhmiss=%time:~0,2%:%time:~3,2%:%time:~6,2%
git add .
git pull
git commit -m "%YYYYmmdd%_%hhmiss%"
git push
pause