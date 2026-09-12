#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>

class Message{
    
    public:
        Message(): bodyLength(0) {}
        enum {maxBytes = 512};
        enum {header = 4};

        Message(std::string message){
            bodyLength = getNewBodyLength(message);
            encodeHeader();
            std::memcpy(data+header, message.c_str(), bodyLength);
        }

        std::string getData(){
            int length = header + bodyLength;
            std::string result(data, length);
            return result;
        }

        std::string getBody(){
            std::string str = getData();
            std::string result = str.substr(header, bodyLength);
            return result;
        }

        void encodeHeader(){
            char newHeader[header +1] = "";
            sprintf(newHeader, "%4d", static_cast<int>(bodyLength));
            std::memcpy(data,  newHeader, header);

        }

        bool decodeHeader(){
            char newHeader[header +1] = "";
            strncpy(newHeader, data, header);
            newHeader[header] = '\0';
            int headerValue = atoi(newHeader);
            if(headerValue > maxBytes){
                bodyLength = 0;
                return false;
            }
            bodyLength = headerValue;
            return true;
        }

        int getNewBodyLength(std::string message){
            if(message.size() > maxBytes){
                return maxBytes;
            }

            return message.size();
        }
    

    private:
        size_t bodyLength;
        char data[header + maxBytes];



};



#endif MESSAGE_HPP