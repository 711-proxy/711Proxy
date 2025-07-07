
      
       
    <?php
    // SOCKS5 proxy configuration
    $proxyHost = 'ip'; // Proxy host
    $proxyPort = '10000'; // Proxy port
    $proxyUser = 'your_username'; // Proxy username (replace with your proxy username, e.g., USERxxxx-zone-custom)
    $proxyPass = 'your_password'; // Proxy password (replace with your proxy password)
    // IP info URL
    $ipInfoUrl = 'https://ipinfo.io/json';

    // Initialize cURL
    $ch = curl_init();

    // Set cURL options
    curl_setopt($ch, CURLOPT_URL, $ipInfoUrl); // URL to request
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); // Return the response as a string
    curl_setopt($ch, CURLOPT_PROXY, $proxyHost . ':' . $proxyPort); // Set the SOCKS5 proxy
    curl_setopt($ch, CURLOPT_PROXYTYPE, CURLPROXY_SOCKS5_HOSTNAME); // Set proxy type as SOCKS5 and resolve DNS through proxy
    curl_setopt($ch, CURLOPT_PROXYUSERPWD, $proxyUser . ':' . $proxyPass); // Proxy username and password
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false); // Disable SSL peer verification (for testing only)
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, false); // Disable SSL host verification (for testing only)
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 30); // 30-second connection timeout
    curl_setopt($ch, CURLOPT_TIMEOUT, 60); // 60-second total timeout

    // Execute the request
    $response = curl_exec($ch);

    // Check for cURL errors
    if ($response === false) {
        echo "cURL Error: " . curl_error($ch) . "";
    } else {
        echo "Response from IP info:";
        echo $response;
    }

    // Close the cURL session
    curl_close($ch);

          
    
