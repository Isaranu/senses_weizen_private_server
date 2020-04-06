var net = require('net');
var port = 5000;

var server = net.createServer(function(client){
    console.log('client connect');

    client.on('data', function(raw){
        console.log(raw);
        var log = raw.toString('ascii');
        console.log(log);
    });
    client.on('end', function(){
        console.log('client disconnected');
    });
    client.write('OK\r\n');
    client.pipe(client);
})

server.listen(port, function(){
    console.log('server is listening ');
})
