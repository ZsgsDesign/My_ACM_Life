@echo off
if "%1"=="" goto loop
copy pyramid%1.in pyramid.in >nul
echo Problem Test
echo Data %1
time<enter
pyramid
time<enter
fc pyramid.out pyramid%1.out
del pyramid.in
del pyramid.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
