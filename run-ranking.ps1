g++ -I./Genetic -I./Shared -I./Greedy .\Shared\*.cpp .\Greedy\*.cpp .\Genetic\*.cpp main.cpp Config.cpp -o result.exe

Get-ChildItem .\instances\ | where Name -notlike "*_best*" | sort Name | % {
  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/$name";

   $result = 0;

  $time = Measure-Command {
  $result = .\result.exe $path;
  }

  $currBest = get-content $path.Replace(".txt", "_best.txt") -First 1;
  "$result - current best: $currBest";
  "Execution took $($time.Minutes):$($time.Seconds)min";

  Write-Host "";
}

rm .\result.exe