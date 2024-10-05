@echo off
cd C:\Users\91630\OneDrive\Desktop\C++   
git add .
git commit -m "Daily DSA progress - %date%"
git pull origin main
git push origin main
pause

