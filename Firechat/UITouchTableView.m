//
//  UITouchTableView.m
//  Firechat
//
//  Created by Anant Narayanan on 12/6/12.
//  Copyright (c) 2012 Firebase. All rights reserved.
//

#import "UITouchTableView.h"

@implementation UITouchTableView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event
{
    NSLog(@"touched");
}

@end
