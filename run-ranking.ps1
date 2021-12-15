g++ -I./Genetic -I./Shared -I./Greedy .\Shared\*.cpp .\Greedy\*.cpp .\Genetic\*.cpp main.cpp Config.cpp -o result.exe

Get-ChildItem .\instances\ | where Name -notlike "*_best*" | sort Name | % {
  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/$name"; 
  .\result.exe $path;
#   Write-Host $result -ForegroundColor Yellow;
  Write-Host "";
}

rm .\result.exe