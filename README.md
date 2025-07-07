# crawler
import requests

proxies = {
    'http': 'http://username:password@global.rotgb.711proxy.com:10000',
}

# proxies = {
#     'http': 'http://165.154.202.156:10000',
# }

try:
    response = requests.get('http://example.com', proxies=proxies, timeout=10)
    print(response.text)
except requests.exceptions.RequestException as e:
    print(f"Request Failed: {e}")
