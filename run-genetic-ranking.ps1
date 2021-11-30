g++ .\Tabu\Tabu.cpp -o .\Tabu\a.exe;

Get-ChildItem .\instances\ | sort Name | % {
  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/$name"; 
  $result = .\Tabu\a.exe $path;
  Write-Host $result -ForegroundColor Yellow;
  Write-Host "";
}