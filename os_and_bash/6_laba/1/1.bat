MD C:\LAB6
touch C:\LAB6\ver.txt
ver > C:\LAB6\ver.txt
touch C:\LAB6\logicaldisk.txt
wmic logicaldisk get description,name > C:\LAB6\logicaldisk.txt
touch C:\LAB6\wmic_memory.txt
wmic computersystem get totalphysicalmemory > C:\LAB6\wmic_memory.txt
wmic os get freephysicalmemory >> C:\LAB6\wmic_memory.txt
mkdir TEST
xcopy "C:\LAB6" "TEST\" /S /E
cd TEST
copy *.txt all.txt
copy all.txt ..\all.txt
del *.txt
copy ..\all.txt all.txt
del ..\all.txt
