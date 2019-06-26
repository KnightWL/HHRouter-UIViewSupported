//  The MIT License (MIT)
//
//  Copyright (c) 2014 LIGHT lightory@gmail.com
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the “Software”), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, HHRouteType) {
    HHRouteTypeNone = 0,
    HHRouteTypeViewController = 1,
    HHRouteTypeBlock = 2
};

typedef id (^HHRouterBlock)(NSDictionary *params);


/**
 * HHRouter
 */
@interface HHRouter : NSObject

+ (instancetype)shared;

- (void)map:(NSString *)route toControllerClass:(Class)controllerClass;
- (UIViewController *)match:(NSString *)route __attribute__((deprecated));
- (UIViewController *)matchController:(NSString *)route;

- (void)map:(NSString *)route toViewClass:(Class)viewClass;
- (UIView *)matchView:(NSString *)route;


- (void)map:(NSString *)route toBlock:(HHRouterBlock)block;
- (HHRouterBlock)matchBlock:(NSString *)route;
- (id)callBlock:(NSString *)route;

- (HHRouteType)canRoute:(NSString *)route;

@end



/**
 * 由View或者Controller来实现的协议，借此来传递一些初始化参数
 * 会在matchController/matchView 方法返回对应obj之前，调用[obj HHRouter_setParams:]
 * 如果一个Controller/View 的初始化不需要额外参数，可以不实现该协议
 */
@protocol HHRouterParamDelegate <NSObject>
- (void)HHRouter_setParams:(NSDictionary *)params;

@end
