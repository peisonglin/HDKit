//
//  KOPJsonObjectCoder.h
//  KOPObjectDecoder
//
//  Created by Mao on 16/8/2.
//  Copyright © 2016年 Mao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JsonObjectCoder : NSObject

+(id)decodeJson:(NSData*)json class:(Class)objectClass;

+(NSData*)encodeObject:(id)object subObjectInfo:(NSDictionary*)subObjectInfo;

+(NSData*)encodeObject:(id)object;

//object为string 转dic
+ (id)stringToDic:(id)object;
/// object为dic或者array 转json
+ (id)toJSONString:(id)object;

///json转字典或者  model转字典
+(NSDictionary*)encodeObjectToDic:(id)object subObjectInfo:(NSDictionary*)subObjectInfo;

//+(NSMutableDictionary *)generateDict:(id)model;

+(NSArray*)decodeArr:(NSArray *)data class:(Class)objectClass;

+(id)decodeDic:(NSDictionary *)dic class:(Class)objectClass;

@end
