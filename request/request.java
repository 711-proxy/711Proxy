
      
       
    import java.io.BufferedReader;
    import java.io.InputStreamReader;
    import java.net.Authenticator;
    import java.net.HttpURLConnection;
    import java.net.InetSocketAddress;
    import java.net.PasswordAuthentication;
    import java.net.Proxy;
    import java.net.URL;

    public class Socks5ProxyRequest {

        public static void main(String[] args) {
            String proxyHost = "ip"; // Proxy host
            int proxyPort = port; // Proxy port
            String proxyUser = "your_username"; // Proxy username (replace with your proxy username, e.g., USERxxxx-zone-custom)
            String proxyPass = "your_password"; // Proxy password (replace with your proxy password)
            // Target URL
            String targetUrl = "https://ipinfo.io/json/";

            try {

                Authenticator.setDefault(new Authenticator() {
                    @Override
                    protected PasswordAuthentication getPasswordAuthentication() {
                        return new PasswordAuthentication(proxyUser, proxyPass.toCharArray());
                    }
                });

                // Create proxy
                Proxy proxy = new Proxy(Proxy.Type.SOCKS, new InetSocketAddress(proxyHost, proxyPort));

                // Create URL object
                URL url = new URL(targetUrl);

                HttpURLConnection connection = (HttpURLConnection) url.openConnection(proxy);

                // Set Request
                connection.setRequestMethod("GET");
                connection.setConnectTimeout(10000);
                connection.setReadTimeout(10000);
                connection.setRequestProperty("User-Agent", "Mozilla/5.0");

                //Connect and get response code
                int responseCode = connection.getResponseCode();

                if (responseCode == 200) {
                    // Read response
                    BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                    String inputLine;
                    StringBuilder response = new StringBuilder();

                    while ((inputLine = in.readLine()) != null) {
                        response.append(inputLine);
                    }
                    in.close();

                    // Print
                    System.out.println(response.toString());
                } else {
                    System.out.println(responseCode);
                }

                // Disconnect
                connection.disconnect();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

          
    
