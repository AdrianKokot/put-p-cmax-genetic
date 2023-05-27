g++ -I./Genetic -I./Shared -I./Greedy .\Shared\*.cpp .\Greedy\*.cpp .\Genetic\*.cpp main.cpp Config.cpp -o main

Get-ChildItem .\instances\report | where Name -like "U*" | %{
  $name = $_.Name.Split('_')[-1];
  $optimum = (Get-ChildItem ".\instances\report\SOL*_$($name)" | get-content -First 3 | select -Last 1).Split(' ')[0];

  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/report/$name";
   $result = .\main $path;
  "Result = $result; Optimum = $optimum"

  Write-Host "";
}

rm .\main