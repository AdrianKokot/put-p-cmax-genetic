g++ -I./Genetic -I./Shared -I./Greedy .\Shared\*.cpp .\Greedy\*.cpp .\Genetic\*.cpp main.cpp Config.cpp -o main

Get-ChildItem .\instances\ | where Name -notlike "*_best*" | sort Name | % {
  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/$name";

   $result = 0;

  $time = Measure-Command {
  $result = .\main $path;
  }

  $currBest = get-content $path.Replace(".txt", "_best.txt") -First 1;
  "$result - current best: $currBest";

  $minutes = $time.Minutes.ToString().PadLeft(2, "0");
  $seconds = $time.Seconds.ToString().PadLeft(2, "0");

  "Execution took $($minutes):$($seconds)min";

  Write-Host "";
}

rm .\main