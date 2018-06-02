open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let container =
    style([flex(1.), backgroundColor(Colors.black), paddingTop(Pt(20.))]);
  let content = style([flex(1.), backgroundColor(Colors.white)]);
  let categories =
    style([
      height(Pt(60.)),
      backgroundColor(Colors.white),
      paddingHorizontal(Pt(80.)),
      flexDirection(Row),
      justifyContent(SpaceBetween),
      alignItems(Center),
    ]);
};

type state = {filter: Category.filter};

type action =
  | SetCategory(Category.category)
  | ClearCategories;

let component = ReasonReact.reducerComponent("RecommendationList");

let make = (~openDetails, _children) => {
  ...component,
  initialState: () => {filter: Category.All},
  reducer: (action, _state) =>
    switch (action) {
    | SetCategory(category) =>
      ReasonReact.Update({filter: Category(category)})
    | ClearCategories => ReasonReact.Update({filter: Category.All})
    },
  render: self => {
    let currentFilter = self.state.filter;
    let recommendations =
      Array.mapi(
        (index, place) =>
          <RecommendationItem
            key=("recommendation-" ++ string_of_int(index))
            openDetails
            place
          />,
        Recommendation.filteredRecommendations(currentFilter),
      );
    <View style=Style.container>
      <NavBar />
      <ScrollView style=Style.content>
        <View style=Style.categories>
          <Category
            filter=All
            currentFilter
            onChange=(self.reduce(_event => ClearCategories))
          />
          <Category
            filter=(Category(Eat))
            currentFilter
            onChange=(self.reduce(_event => SetCategory(Category.Eat)))
          />
          <Category
            filter=(Category(See))
            currentFilter
            onChange=(self.reduce(_event => SetCategory(Category.See)))
          />
        </View>
        (ReasonReact.arrayToElement(recommendations))
      </ScrollView>
    </View>;
  },
};