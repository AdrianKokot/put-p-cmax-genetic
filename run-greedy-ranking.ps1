g++ .\Greedy\Greedy.cpp -o .\Greedy\a.exe;

Get-ChildItem .\instances\ | sort Name | % {
  $name = $_.Name;
  Write-Host $name -ForegroundColor Green;
  $path = "./instances/$name"; 
  $result = .\Greedy\a.exe $path;
  Write-Host $result -ForegroundColor Yellow;
  Write-Host "";
}