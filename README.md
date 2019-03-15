# OMC SDK


OMC SDK is full fledged Push SDK with RRT, Geofence, Beacon events sent to Infinity.

## Configuration

### Configure OMC SDK

- Adding the OMC SDK Framework
    - Download the latest framework binary.
    - Drag and Drop the framework into your project. (select Copy when prompted for adding reference)
    - In your application target setting, add the OMCSDK.framework to the Embedded Binaries section.
    - Ensure that in application target build settings, Framework Search Path is set to correct location of OMC.framework.
    
### Configure Responsys

  - Follow the Step 1, Step 3 to Step 8 configure OMC SDK from [Configure Responsys][PushRef]

### Configure Infinity
To configure Infinity, application need to have Oracle.plist. It contains the infinity configuration.
  - Oracle.plist
    - Download the [Oracle.plist][OraclePlistRef]
    - Drag and Drop it into your application Xcode Project.
    - Open the Oracle.plist and change the value of `ora_dc_account_guid` to the value of your team/configuration in Infinity.
        - How to get the `ora_dc_account_guid`:
            - login to [Infinity][InfinityRef]
            - Select the team (if multiple teams are listed).
            - Select the profile icon (on top right corner).
            - Guid is displayed below your team name.
### Test

  - Login in [Infinity][InfinityRef]
  - Select Stream
    + [Streams reference][StreamRef]
  - Start the Stream
 - Trigger event e.g.:

```swift
[[PushIOManager sharedInstance] trackEvent:@"$PurchasedCart" properties:@{@"pid":@"165SFDFD121", @"pname":@"Shirt"}];
``` 
  - Stream should show the event i.e.: `$PurchasedCart` captured along with other metadata.
  
  ## Oracle Marketing Cloud SDK for iOS: Documentation
* [Integration Guide][Docs]

[PushRef]: <https://docs.oracle.com/cloud/latest/marketingcs_gs/OMCFB/ios/step-by-step/>
[InfinityRef]: <http://app.oracleinfinity.com/>
[StreamRef]: <https://docs.oracle.com/cloud/latest/marketingcs_gs/OMCHA/Help/streams.htm>
[OraclePlistRef]: <https://raw.githubusercontent.com/pushio/omc-ios/master/oracle.plist>
[Docs]: <https://docs.oracle.com/cloud/latest/marketingcs_gs/OMCFB/ios/>

