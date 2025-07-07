
      
       
    // user:pass http
    require("request-promise")({
      url: "http://ipinfo.io/json",
      proxy: "http://user:pass@global.rotgb.711proxy.com:10000",
    }).then(
      function (data) {
        console.log(data);
      },
      function (err) {
        console.error(err);
      }
    );
  
    
