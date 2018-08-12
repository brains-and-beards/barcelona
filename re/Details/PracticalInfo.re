open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let container = style([flex(1.), backgroundColor(Colors.white), paddingHorizontal(Pt(50.)), paddingBottom(Pt(30.))]);
  let itemContainer =
    style([flexDirection(Row), backgroundColor(Colors.white), paddingVertical(Pt(5.))]);
  let icon = style([height(Pt(30.)), width(Pt(100.)), justifyContent(Center), alignItems(Center) ]);
  let iconContainer = style([flex(1.), justifyContent(Center), alignItems(Center)]);
  let infoText = style([fontSize(Float(14.)), fontFamily("Poppins"), fontWeight(`_600) ]);
  let infoTextContainer = style([flex(3.), justifyContent(Center)]);
};

let component = ReasonReact.statelessComponent("PracticalInfo");

let make = (~info: Recommendation.practicalInfo, _children) => {
  ...component,
  render: _self =>
    <View style=Style.container>
      <View style=Style.itemContainer>
        <View style=Style.iconContainer>
          <Image
            source=BsReactNative.Image.(
                    Required(
                      BsReactNative.Packager.require(
                        "../../../../assets/location.png",
                      ),
                    )
                  )
            style=Style.icon
            resizeMode=`contain
          />
        </View>
        <View style=Style.infoTextContainer>
          <Text value=(String.uppercase(info.location)) style=Style.infoText />
        </View>
      </View>

      <View style=Style.itemContainer>
      <View style=Style.iconContainer>
          <Image
            source=BsReactNative.Image.(
                    Required(
                      BsReactNative.Packager.require(
                        "../../../../assets/hours.png",
                      ),
                    )
                  )
            style=Style.icon
            resizeMode=`contain
          />
        </View>
        <View style=Style.infoTextContainer>
          <Text value=(String.uppercase(info.hours)) style=Style.infoText />
        </View>
      </View>

      <View style=Style.itemContainer>
        <View style=Style.iconContainer>
          <Image
          source=BsReactNative.Image.(
                  Required(
                      BsReactNative.Packager.require(
                      "../../../../assets/phone.png",
                      ),
                  )
                  )
          style=Style.icon
          resizeMode=`contain
          />
          </View>
          <View style=Style.infoTextContainer>
            <Text value=(String.uppercase(info.contact)) style=Style.infoText />
          </View>
      </View>

    </View>,
};