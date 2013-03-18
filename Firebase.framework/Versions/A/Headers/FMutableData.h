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

@interface FMutableData : NSObject

//- (id) initWithValue:(id)value;
- (FMutableData *) childDataByAppendingPath:(NSString *)path;

- (BOOL) isEqualToData:(FMutableData *)other;

@property (strong, readonly, nonatomic) FMutableData* parent;
@property (strong, nonatomic) id value;
@property (strong, nonatomic) id priority;
@property (readonly, nonatomic) NSUInteger childrenCount;
@property (readonly, nonatomic, strong) NSEnumerator* children;
@property (readonly, nonatomic, strong) NSString* name;
//- (void) set:(id)value;
//- (void) setPriority:(id)priority;
//- (id) val;
//- (id) getPriority;
- (BOOL) hasChildren;
- (BOOL) hasChildAtPath:(NSString *)path;
//- (int) numChildren;
//- (NSString *) name;

@end
