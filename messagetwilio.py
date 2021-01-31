sms = Sms(credentials.account_sid,credentials.auth_token,credentials.my_mobile,credentials.my_cell)
def sendit():
    while True:
        print ("Reading sensor value")
        response = mybolt.digitalRead('0')
        data = json.loads(response)
        print("Sensor value is: " + str(data['value']))
        try:
            sensor_value = int(data['value'])
            if sensor_value<=100:
                print("Making request to Twilio to send a SMS ")          
                response = sms.send_sms("maintain social distance" +str(sensor_value))
                print("Response received from Twilio is: " + str(response))
                print("Status of SMS at Twilio is :" + str(response.status))

        except Exception as e:
            print ("Error occured: Below are the details")
            print (e)
        time.sleep(10)
