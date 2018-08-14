open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let container =
    style([
      flex(1.),
      backgroundColor(Colors.brainsYellow),
      alignItems(Center),
      justifyContent(Center),
    ]);
  let image =
    style([height(Pt(375.)), width(Pt(float_of_int(Theme.width)))]);
  let description =
    style([
      fontFamily("Poppins"),
      fontSize(Float(18.)),
      paddingHorizontal(Pt(30.)),
      textAlign(Center),
      paddingVertical(Pt(20.)),
      lineHeight(22.),
    ]);
  let actionButtonText =
    style([
      fontFamily("Poppins"),
      fontWeight(`_600),
      fontSize(Float(25.)),
    ]);
  let actionButtonContainer =
    style([
      borderColor(Colors.black),
      borderWidth(2.),
      paddingHorizontal(Pt(40.)),
      paddingVertical(Pt(10.)),
    ]);
};

let component = ReasonReact.statelessComponent("IntroScreen");

let welcomeText = {js|Welcome to Brains & Beards\nguide around sunny Barcelona. \n Check out some cool places\nwe recommend!|js};

let make = (~showRecommendation, _children) => {
  ...component,
  render: _self =>
    <View style=Style.container>
      <Image
        source=BsReactNative.Image.(
                 Required(
                   BsReactNative.Packager.require(
                     "../../../../assets/intro.png",
                   ),
                 )
               )
        resizeMode=`contain
        style=Style.image
      />
      <Text value=welcomeText style=Style.description />
      <TouchableOpacity
        onPress=showRecommendation style=Style.actionButtonContainer>
        <Text value="LET'S GO" style=Style.actionButtonText />
      </TouchableOpacity>
    </View>,
};