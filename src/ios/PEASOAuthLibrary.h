//
//  PEASOAuthLibrary.h
//  PEASOAuthLibrary
//
//  Created by Gautam Zodape on 30/04/14.
//  Copyright (c) 2014 Gautam Zodape. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PEASOAuthLibrary : NSObject

{
    // redirect url for app, it must be a url scheme of app
	NSString *redirectUri;
    
    //    it is access token genrated by oAuth library
	NSString *accessToken;
    
    //	Server URL which will authenticate user and revert back with code and access tken
    NSString* serverUrl;
    
    //    Secrete key of oAuth server
    NSString* secreteKey;
    
    //    Consumer/public key of oAuth server
    NSString* consumerKey;
    
    //    the class object which will responsible for accesing access token from libray via call back selectore
	id callbackObject;
    
    //    the selector method which will call after getting access token from server
	SEL callbackSelector;
}

@property (nonatomic, strong) NSString *serverUrl;
@property (nonatomic, strong) NSString *secreteKey;
@property (nonatomic, strong) NSString *consumerKey;
@property (nonatomic, strong) NSString *redirectUri;
@property (nonatomic, strong) NSString *accessToken;


@property (strong) id callbackObject;
@property (readwrite) SEL callbackSelector;

/**
 * @fn     - (id)initWithServerURl:(NSString*) strUrl redirectURL:(NSString*)schemeUrl consumerKey:(NSString*) consumersKey andSecretKey:(NSString*)secretkey
 * @brief  it initialize the oAuth manager class with the required parameters
 * @param  strUrl : it is a oAuth server url .
 * @param  schemeUrl : it is app url scheme which will used by oAuth server to redirect back into app after successfull
 * autherisation.
 * @param  consumersKey : it is a public key of oAuth server .
 * @param  secretkey : it is a secret key of oAuth server url .
 * @return id : created oAuthmanager class object initializd with provided parameter.
 */

- (id)initWithServerURl:(NSString*) strUrl redirectURL:(NSString*)schemeUrl consumerKey:(NSString*) consumersKey andSecretKey:(NSString*)secretkey;

/**
 * @fn     - (void)sendRequestForAccessTokenWithUrl:(NSURL*) url;
 * @brief  it starts the access token genrating process on oauth server and return back the access token to selector methods
 * @param  url : it is a redirected url come from browser after login.
 * @return void
 */
- (void)sendRequestForAccessTokenWithUrl:(NSURL*) url;

/**
 * @fn     -(void)authenticateUserWithCallbackObject:(id)anObject selector:(SEL)selector;
 * @brief  it start the authentication process of user. and communicate with oAuth server for autherisation
 * @param  anObject : it is a delegate handler class which is responsible accessing token generated by oAuth manager .
 * @param  selector : it is selector method in which access token is collected.
 * @return void.
 */
-(void)authenticateUserWithCallbackObject:(id)anObject selector:(SEL)selector;

/**
 * @fn     +(id) sharedInstance;
 * @brief  it returns the previously created object if it is not initialize then user have to set serverUrl, secreteKey,consumerKey, redirectUri manually.
 * @return void.
 */
+(id) sharedInstance;

@end


