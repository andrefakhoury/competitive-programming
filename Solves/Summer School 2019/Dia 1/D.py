# -*- coding: utf-8 -*-
 
n = int(input())
emails = set()
 
for i in range(n):
	email = input()
	user, provider = email.split('@')
 
	if('+' in user):
		user, dump = email.split('+')
 
	user = user.replace('.', '')
	email = user + '@' + provider
 
	emails.add(email)
 
print(len(emails))