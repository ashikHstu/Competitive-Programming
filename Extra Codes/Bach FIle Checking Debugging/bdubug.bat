@echo off
gen >in.txt
sol   <in >out.txt
brute <in >ok.txt
fc out ok.txt
if ErrorLevel 1 exit /b
bach