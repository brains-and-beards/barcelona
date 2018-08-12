open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let container = style([flex(1.), backgroundColor(Colors.white)]);
  let categories =
    style([
      height(Pt(60.)),
      backgroundColor(Colors.white),
      paddingHorizontal(Pt(80.)),
      flexDirection(Row),
      justifyContent(SpaceBetween),
      alignItems(Center),
    ]);
  let image =
    style([height(Pt(200.)), width(Pt(float_of_int(Theme.width)))]);
  let title =
    style([
      fontSize(Float(32.)),
      fontFamily("Poppins"),
      fontWeight(`_600),
      paddingHorizontal(Pt(25.)),
      paddingTop(Pt(10.)),
      paddingBottom(Pt(10.)),
    ]);
  let tagline =
    style([
      fontSize(Float(14.)),
      fontFamily("Poppins"),
      fontWeight(`_600),
      paddingHorizontal(Pt(25.)),
      paddingBottom(Pt(10.)),
    ]);
  let description =
    style([
      fontSize(Float(18.)),
      fontFamily("Poppins"),
      paddingHorizontal(Pt(25.)),
      marginVertical(Pt(35.)),
      lineHeight(27.),
    ]);
  let recommendationContainer =
    style([
      height(Pt(200.)),
      justifyContent(Center),
      alignItems(Center),
      marginTop(Pt(-375.)),
      marginBottom(Pt(200.)),
    ]);
  let recommendation =
    style([
      fontSize(Float(25.)),
      fontFamily("Poppins"),
      marginHorizontal(Pt(40.)),
      textAlign(Center),
    ]);
  let quoteBackgroundImage =
    style([
      backgroundColor(String("#fff")),
      height(Pt(400.)),
      width(Pt(400.)),
    ]);
};

let component = ReasonReact.statelessComponent("RecommendationDetails");

let make = (~placeID, _children) => {
  ...component,
  render: _self => {
    let place = Recommendation.find(placeID);
    let description = place.description;
    <ScrollView style=Style.container>
      <Text value=place.title style=Style.title />
      <Text value=(String.uppercase(place.tagline)) style=Style.tagline />
      <Image source=place.image resizeMode=`cover style=Style.image />
      <Text value={j|$(description)|j} style=Style.description />
      <PracticalInfo info=place.practicalInfo />
      <Image
        source=BsReactNative.Image.(
                 Required(
                   BsReactNative.Packager.require(
                     "../../../../assets/quote-background.png",
                   ),
                 )
               )
        style=Style.quoteBackgroundImage
        resizeMode=`contain
      />
      <View style=Style.recommendationContainer>
        <Text value=place.recommendation style=Style.recommendation />
      </View>
    </ScrollView>;
  },
};