/*
 * Firebase iOS Client Library
 *
 * Copyright © 2013 Firebase - All Rights Reserved
 * https://www.firebase.com
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binaryform must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY FIREBASE AS IS AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL FIREBASE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "FEventType.h"
#import "FDataSnapshot.h"

typedef NSUInteger FirebaseHandle;


@interface FQuery : NSObject


// Read Data


- (FirebaseHandle) observeEventType:(FEventType)eventType withBlock:(void (^)(FDataSnapshot* snapshot))block;


- (FirebaseHandle) observeEventType:(FEventType)eventType andPreviousSiblingNameWithBlock:(void (^)(FDataSnapshot* snapshot, NSString* prevName))block;


- (FirebaseHandle) observeEventType:(FEventType)eventType withBlock:(void (^)(FDataSnapshot* snapshot))block withCancelBlock:(void (^)(void))cancelBlock;


- (FirebaseHandle) observeEventType:(FEventType)eventType andPreviousSiblingNameWithBlock:(void (^)(FDataSnapshot* snapshot, NSString* prevName))block withCancelBlock:(void (^)(void))cancelBlock;


- (void) removeObserverWithHandle:(FirebaseHandle)handle;


- (void) removeAllObservers;


- (void) observeSingleEventOfType:(FEventType)eventType withBlock:(void (^)(FDataSnapshot* snapshot))block;


- (void) observeSingleEventOfType:(FEventType)eventType andPreviousSiblingNameWithBlock:(void (^)(FDataSnapshot* snapshot, NSString* prevName))block;


- (void) observeSingleEventOfType:(FEventType)eventType withBlock:(void (^)(FDataSnapshot* snapshot))block withCancelBlock:(void (^)(void))cancelBlock;


- (void) observeSingleEventOfType:(FEventType)eventType andPreviousSiblingNameWithBlock:(void (^)(FDataSnapshot* snapshot, NSString* prevName))block withCancelBlock:(void (^)(void))cancelBlock;


// Obtain a further-constrained query


- (FQuery *) queryStartingAtPriority:(id)startPriority;


- (FQuery *) queryStartingAtPriority:(id)startPriority andChildName:(NSString *)childName;


- (FQuery *) queryEndingAtPriority:(id)endPriority;


- (FQuery *) queryEndingAtPriority:(id)endPriority andChildName:(NSString *)childName;


- (FQuery *) queryLimitedToNumberOfChildren:(NSUInteger)limit;

@end
