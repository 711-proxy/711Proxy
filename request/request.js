
      
       
    // user:pass http
    require("request-promise")({
      url: "http://ipinfo.io/json",
      proxy: "http://user:pass@ip:port",
    }).then(
      function (data) {
        console.log(data);
      },
      function (err) {
        console.error(err);
      }
    );
  
    
