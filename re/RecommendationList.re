open ReactNative;

let component = ReasonReact.statelessComponent "RecommendationList";

let contentStyle = Style.(style [flex 1., justifyContent `center, alignItems `center]);

let containerStyle = Style.(style [flex 1.]);

let make _children => {
  ...component,
  render: fun _self =>
    <View style=containerStyle>
      <NavBar />
      <RecommendationItem
        id=1
        title="Recommendations"
        description="The holy church on top of the mountain is a wonderful place of worship and climbing. There are also cool via ferratas to visit and the MOntserrat Mujahedins that will keep you on your toes all the time. Heartily recommend!"
        rating=3
      />
    </View>
};
