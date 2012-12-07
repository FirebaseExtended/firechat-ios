//
//  UITouchTableView.m
//  Firechat
//
//  Copyright (c) 2012 Firebase.
//
//  No part of this project may be copied, modified, propagated, or distributed
//  except according to terms in the accompanying LICENSE file.
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
    [self.nextResponder touchesBegan:touches withEvent:event];
}

@end
