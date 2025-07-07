
      
       
    # user:pass socks5
    import requests

    response = requests.get(
        "http://ipinfo.io/",
        proxies={
            "http": "socks5://user:pass@ip:port",
            "https": "socks5://user:pass@ip:port",
        },
    )
    print(response.text)

    # user:pass http

    import requests

    response = requests.get(
        "http://ipinfo.io/",
        proxies={
            "http": "http://user:pass@ip:port",
            "https": "http://user:pass@ip:port",
        },
    )
    print(response.text)

          
    
