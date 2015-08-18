var fs = require('fs');
var readline = require('readline');

var rd = readline.createInterface({
  input: fs.createReadStream('captured.csv'),
  terminal: false
});

var cnt = 0;
var ma = 0;

rd.on('line', function(line) {
  var parts = line.split(',');
  var num = parseInt(parts[2]);
  ma = ma * 0.999 + num * 0.001;
  cnt++;
  if(cnt % 10000 == 0) {
    console.log(ma);
  }
});
