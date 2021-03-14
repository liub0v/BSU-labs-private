import requests

response = requests.get('http://localhost:5000')
if response.status_code == 200:
    print('Success!')
elif response.status_code == 404:
    print('Not Found.')


response1 = requests.post('http://localhost:5000', files={'file': open('D:/study/хакатон/FlaskProject/file.txt', 'rb')})
if response1.status_code == 200:
    print('Success!')
elif response1.status_code == 404:
    print('Not Found.')