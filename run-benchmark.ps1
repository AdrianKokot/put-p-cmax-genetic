g++ -I./Genetic -I./Shared -I./Greedy .\Shared\*.cpp .\Greedy\*.cpp .\Genetic\*.cpp main.cpp Config.cpp -o result.exe

Get-ChildItem .\instances\sprawozdanie | where Name -like "U*" | %{
  $name = $_.Name.Split('_')[-1];
  $optimum = (Get-ChildItem ".\instances\sprawozdanie\SOL*_$($name)" | get-content -First 3 | select -Last 1).Split(' ')[0];

    $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/sprawozdanie/$name";
   $result = .\result.exe $path;
  "Result = $result; Optimum = $optimum"

  Write-Host "";
}

rm .\result.exe