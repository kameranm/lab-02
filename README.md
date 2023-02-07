# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Kameran Mody
- Greg Sarandi

## Lab Question Answers

Answer for Question 1: 

Question 1: How did the reliability of UDP change when you added 50% loss to your local
environment? Why did this occur?
The UDP was very unreliable when I added a 50% loss to the local environment. It only worked about 50 % of the time. This occurred because there was a 50% loss implemented to the system so about half the time, the data sent over from the server to client was dropped. 

Question 2: How did the reliability of TCP change? Why did this occur?
The reliability of TCP changed a lot with the change as it gradually got slower and eventually just stopped sending the data from the server to the client. This is because TCP is connection oriented and once the connection was lost, it did not recover and send any more data. 

Question 3: How did the speed of the TCP response change? Why might this happen?
The speed of the TCP response was a lot slower than the UDP connection. This is because TCP is known for being slower than UDP but a lot more reliable than UDP. Since a connection is made, the sending of data is simply slower but is guaranteed. I may have not waited long enough to see some of the TCP data go through since it was going so slow. 

