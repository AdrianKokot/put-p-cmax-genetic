g++ .\Greedy\main.cpp -o .\greedy.exe;

Get-ChildItem .\instances\ | sort Name | % {
  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/$name"; 
  $result = .\greedy.exe $path;
  Write-Host $result -ForegroundColor Yellow;
  Write-Host "";
}

rm .\greedy.exe