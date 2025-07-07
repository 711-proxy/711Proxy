
      
       
    package main

    import (
    	"log"

    	"github.com/go-resty/resty/v2"
    )

    func main() {
    	// user:pass socks5
    	client := resty.New()
    	client.SetProxy("socks5://user:pass@ip:port")
    	response, err := client.R().Get("http://ipinfo.io/json")
    	if err != nil {
    		panic(err)
    	}
    	log.Println(string(response.Body()))

    	// user:pass http
    	client = resty.New()
    	client.SetProxy("http://user:pass@ip:port")
    	response, err = client.R().Get("http://ipinfo.io/json")
    	if err != nil {
    		panic(err)
    	}
    	log.Println(string(response.Body()))
    }

          
    
