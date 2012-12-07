//
//  FTypedefs.h
//  Firebase
//
//  Created by Vikrum Nijjar on 9/6/12.
//
//

#import <Foundation/Foundation.h>

/**
 * Stub...
 */
@class FDataSnapshot;

// fbt = Firebase Block Typedef

typedef void (^fbt_void_void)(void);
typedef void (^fbt_void_datasnapshot_nsstring) (FDataSnapshot *snapshot, NSString *prevName);
typedef void (^fbt_void_datasnapshot) (FDataSnapshot *snapshot);
typedef BOOL (^fbt_bool_datasnapshot) (FDataSnapshot *snapshot);
typedef void (^fbt_void_bool)(BOOL status);